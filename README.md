# PIC18F45K50 <--I2C--> SSD1306 ( buffered version )
This is the converted CCS version ( based on Adafruit ) of SSD1306 (buffered) Driver, working on XC8 v3.00 &amp; MPLAB X IDE 6.20.

![](https://github.com/thetrung/45K50_SSD1306_I2C_buffered/blob/master/Overview_SSD1306_I2C.png)

### NOTE
I had hard time finding library that can let my `PIC18F45K50` run that `SSD1306 128x64 Display(0x3C)` on latest MPLAB version (as Apirl 2025: 6.20 on MacOS), so I tried a lot of things to see how it actually works, or my display was broken. Ended up making the unbuffered version work first (with very limited functionality but require only 48 bytes of RAM), thenfound this CCS-based version (with 1KB buffer).

Although it wasn't as easy as saying, but I can apply what I learned from my unbuffered version to make this work eventually. Even slightiest wrong during I2C transmission or wrong init config may result in nothing show up on the display.

### FACTs
- Tested on SSD1306 Display model `128x64 :: GND-VCC-SCL-SDA`
- May work on any 8-bit PIC with enough SRAM (> 1024 Bytes) & Flash (>14KB), and a built-in I2C.
**CONS:** Idk why yet, but Font rendering is ugly AF, the rest seem fine with minor glitches.
**PROS:** Can draw any shape smoothly, way better than my crappy Pico + Arduino IDE version.

- MPLAB X IDE so outdated that It don't even have code-completion & tooltip hints, so only use that for debugging & VSCode + Clangd for everything else.
