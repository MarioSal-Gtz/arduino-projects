// GIFDraw callback function - Called by AnimatedGIF library

#define DISPLAY_WIDTH  tft.width()
#define DISPLAY_HEIGHT tft.height()
#define BUFFER_SIZE 256  // Reduced for smaller ESP32-S3

uint16_t usTemp[1][BUFFER_SIZE];  // Smaller buffer for memory optimization

void GIFDraw(GIFDRAW *pDraw) {
  uint8_t *s;
  uint16_t *d, *usPalette;
  int x, y, iWidth, iCount;

  // Display bounds check and cropping
  iWidth = pDraw->iWidth;
  if (iWidth + pDraw->iX > DISPLAY_WIDTH)
    iWidth = DISPLAY_WIDTH - pDraw->iX;

  usPalette = pDraw->pPalette;
  y = pDraw->iY + pDraw->y;

  if (y >= DISPLAY_HEIGHT || pDraw->iX >= DISPLAY_WIDTH || iWidth < 1)
    return;

  s = pDraw->pPixels;

  // Handle transparency disposal
  if (pDraw->ucDisposalMethod == 2) {
    for (x = 0; x < iWidth; x++) {
      if (s[x] == pDraw->ucTransparent)
        s[x] = pDraw->ucBackground;
    }
    pDraw->ucHasTransparency = 0;
  }

  // Draw pixels with transparency support
  if (pDraw->ucHasTransparency) {
    uint8_t *pEnd, c, ucTransparent = pDraw->ucTransparent;
    pEnd = s + iWidth;
    x = 0;
    iCount = 0;

    while (x < iWidth) {
      c = ucTransparent - 1;
      d = &usTemp[0][0];

      while (c != ucTransparent && s < pEnd && iCount < BUFFER_SIZE) {
        c = *s++;
        if (c == ucTransparent) {
          s--;
        } else {
          *d++ = usPalette[c];
          iCount++;
        }
      }

      if (iCount) {
        tft.setAddrWindow(pDraw->iX + x, y, iCount, 1);
        tft.pushPixels(usTemp, iCount);
        x += iCount;
        iCount = 0;
      }

      c = ucTransparent;
      while (c == ucTransparent && s < pEnd) {
        c = *s++;
        if (c == ucTransparent)
          x++;
        else
          s--;
      }
    }
  } else {
    // No transparency - optimized drawing
    s = pDraw->pPixels;

    if (iWidth <= BUFFER_SIZE)
      for (iCount = 0; iCount < iWidth; iCount++)
        usTemp[0][iCount] = usPalette[*s++];
    else
      for (iCount = 0; iCount < BUFFER_SIZE; iCount++)
        usTemp[0][iCount] = usPalette[*s++];

    tft.setAddrWindow(pDraw->iX, y, iWidth, 1);
    tft.pushPixels(&usTemp[0][0], iCount);

    iWidth -= iCount;

    while (iWidth > 0) {
      if (iWidth <= BUFFER_SIZE)
        for (iCount = 0; iCount < iWidth; iCount++)
          usTemp[0][iCount] = usPalette[*s++];
      else
        for (iCount = 0; iCount < BUFFER_SIZE; iCount++)
          usTemp[0][iCount] = usPalette[*s++];

      tft.pushPixels(&usTemp[0][0], iCount);
      iWidth -= iCount;
    }
  }
}
