
/* Include DigitLedDisplay Library */
#include "LedControl.h"


LedControl lc = LedControl(13, 14, 12, 8);

int segments = 8 ;

void ConvertSegment(String val) {

  lc.clearDisplay(0);
  // lc.shutdown(0, true);
  //lc.shutdown(0, false);
 // lc.setIntensity(0, 8);

  int cnt = strlen(val.c_str());
  String vv = "";

  int adjust = 1;

  for (int i = 0; i < cnt; i++) {

    vv = val.substring(i, i + 1); //numero a numero

    if (val.indexOf(".") == i + 1) //antecipacao do valor decimal e do digito antes
    {
      lc.setDigit(0, cnt - i - adjust, vv.toInt(), true); //com decimal
    } else {
      if (vv == ".")
        cnt++;//passa um segmento
      else if (vv != "")
        lc.setDigit(0, cnt - i - adjust, vv.toInt(), false); //sem decimal


         delay(5);//fix some random clear digits
    }

  }

}

void setup() {

    lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);

  for (int a = 0; a < 8; a++)
  {
    lc.setChar(0, a, '-', false);
  }

  delay(3000);

}

void loop() {

//ConvertSegment("12345678");
ConvertSegment(String(millis()));

  delay(50);

}
