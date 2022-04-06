
// This is the command sequence that rotates the GC9106 driver coordinate frame
// INitial version for 160x80 0.96 tft display

// The mirroring rotation effect on display depends on how the controller chip is wired to the
// TFT panel. If your display works, but the image appears mirrored, you probably have to change the following lines
// in order to fit the display wiring. It's necessary to preserve TFT_MAD_COLOR_ORDER bit
// The bits that change orientation and load direction are the following
// TFT_MAD_MY
// TFT_MAD_MX
// TFT_MAD_MV

// I let the original code lines commented for you to see how different was the wiring in the OP's display than mine!


  rotation = m % 4;

  writecommand(TFT_MADCTL);
  Serial.printf("ROT: %d",rotation);
  switch (rotation) {
    case 0: // Portrait
       
      // writedata(TFT_MAD_COLOR_ORDER); original
       writedata( TFT_MAD_MY | TFT_MAD_COLOR_ORDER); // If display appears mirrored, you have to change this line
       _width  = _init_width;
       _height = _init_height;
       colstart = 24;
       rowstart = 0;
      break;
    case 1: // Landscape (Portrait + 90)
      //writedata(TFT_MAD_MX | TFT_MAD_MV | TFT_MAD_COLOR_ORDER );
      writedata( TFT_MAD_MV | TFT_MAD_COLOR_ORDER);    // If display appears mirrored, you have to change this line
      _width  = _init_height;
      _height = _init_width;
       colstart = 0;
       rowstart = 24;

      break;
    case 2: // Inverter portrait
      //writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
      writedata(TFT_MAD_MX | TFT_MAD_COLOR_ORDER);     // If display appears mirrored, you have to change this line
      _width  = _init_width;
      _height = _init_height;
       colstart = 24;
       rowstart = 0;
      break;
    case 3: // Inverted landscape
      //writedata(TFT_MAD_MV | TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
      writedata( TFT_MAD_MV |  TFT_MAD_MY| TFT_MAD_MX | TFT_MAD_COLOR_ORDER); // If display appears mirrored, you have to change this line
      _width  = _init_height;
      _height = _init_width;
       rowstart = 24;
       colstart = 0;
      break;
  }
