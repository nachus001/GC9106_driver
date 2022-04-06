
// This is the command sequence that rotates the GC9106 driver coordinate frame
// INitial version for 160x80 0.96 tft display

//   rotation = m % 4; // Limit the range of values to 0-3
//   writecommand(TFT_MADCTL);
//   switch (rotation) {
//     case 0:
     
//        writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_MH | TFT_MAD_COLOR_ORDER);
//        colstart = 24;
//        rowstart = 0;
//       _width  = _init_width;
//       _height = _init_height;
//        break;
//     case 1:
     
//        writedata(TFT_MAD_MV | TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
//        colstart = 0;
//        rowstart = 24;
//       _width  = _init_height;
//       _height = _init_width;
//       break;
//     case 2:
//        writedata(TFT_MAD_COLOR_ORDER);
//        colstart = 24;
//        rowstart = 0;
//       _width  = _init_width;
//       _height = _init_height;
//       break;
//     case 3:
//        writedata(TFT_MAD_MX | TFT_MAD_MV | TFT_MAD_COLOR_ORDER);
//        colstart = 0;
//        rowstart = 24;
//       _width  = _init_height;
//       _height = _init_width;
//       break;
//   }



  rotation = m % 4;

  writecommand(TFT_MADCTL);
  Serial.printf("ROT: %d",rotation);
  switch (rotation) {
    case 0: // Portrait
       
      // writedata(TFT_MAD_BGR); original
       writedata( TFT_MAD_MY | TFT_MAD_COLOR_ORDER);
       _width  = _init_width;
       _height = _init_height;
       colstart = 24;
       rowstart = 0;
      break;
    case 1: // Landscape (Portrait + 90)
      //writedata(TFT_MAD_MX | TFT_MAD_MV | TFT_MAD_BGR);
      writedata( TFT_MAD_MV | TFT_MAD_COLOR_ORDER);
      _width  = _init_height;
      _height = _init_width;
       colstart = 0;
       rowstart = 24;

      break;
    case 2: // Inverter portrait
      //writedata(TFT_MAD_MX | TFT_MAD_MY | TFT_MAD_BGR);
      writedata(TFT_MAD_MX | TFT_MAD_COLOR_ORDER);
      _width  = _init_width;
      _height = _init_height;
       colstart = 24;
       rowstart = 0;
      break;
    case 3: // Inverted landscape
      //writedata(TFT_MAD_MV | TFT_MAD_MY | TFT_MAD_BGR);
      writedata( TFT_MAD_MV |  TFT_MAD_MY| TFT_MAD_MX | TFT_MAD_COLOR_ORDER);
      _width  = _init_height;
      _height = _init_width;
       rowstart = 24;
       colstart = 0;
      break;
  }
