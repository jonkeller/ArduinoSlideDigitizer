/*
 * Hardware ingredients:
 * 
 * Kodak Carousel slide projector.  I used model 550.
 * Arduino.  I used a Mega 1280.
 * Canon DSLR camera.  I used a 450D + kit 18-55mm lens + ND4 filter + Sony VCL-M3358 macro lens.
 * SainSmart relay module. I used the 4-channel model, but only 1 channel is used.
 * R56 relay
 * Breadboard
 * A wire with a 2.5mm 3-contact jack on the end.
 *
 * It is likely that this could be customized to use a different camera, a different projector,
 * etc. but I've only tested with the equipment to which I have access.
 *
 * Building the circuit:
 
 * The Kodak Carousel slide projector has a remote port on it, with 5 holes
 * arranged in the center and the corners (think of dice).  The center hole is
 * the common, and the upper right controls the "advance" button.  Making a connection
 * here will advance the projector.  The potential difference between these two is 24V A/C.
 * Wire the center hole to the center terminal of one of the SainSmart relay channels.
 * Wire the upper right hole to the top terminal of that relay channel (when the text
 * "4 Relay Module is right side up).  I bought some probes to go in the holes, and
 * the probes are connected to wires which have alligator clips on the other ends, which
 * made this physical connection very easy.
 *
 * Connect GND and VCC of the Arduino to the breadboard.  Connect the GND and VCC of the
 * SainSmart relay module to the same lines on the breadboard.  A header to fit over the
 * GND/IN1/IN2/IN3/IN4/VCC pins of the relay module would be helpful here, but you could also
 * do wire-wrapping, direct soldering, tape, etc.
 *
 * Connect the IN1 (or whichever relay channel you used above) of the SainSmart relay module to
 * the breadboard, and connect the same line to the pin number of the Arduino that is
 * indicated by the ADVANCE_SLIDE_PIN constant below.
 *
 * The 2.5mm jack that plugs into the camera has 3 contacts.  The middle one (focus) will
 * not be used.  Connecting the base (common) and tip (shutter) contacts will take a picture,
 * provided the camera is in manual focus mode.  Using the breadboard, connect the wires that
 * go to the base and tip to pins 8 and 14 of the R56.  It doesn't matter which order.  Connect
 * pin 6 to GND.  Connect pin 2 to the pin number of the Arduino that is indicated by
 * the TAKE_PHOTO_PIN constant below.
 *
 * Optics:
 *
 * Remove the projection lens from the slide projector.  Shove the camera lens into the
 * hole that the projection lens came out of.  Focus the camera on a slide.  I found that
 * this was still too bright, and there were streaks caused by the internal lenses of the
 * projector.  I solved this by inserting a piece of paper.  The lineup is as follows:
 * Bulb -> lens 1 -> heat glass -> lens 2 -> paper -> slide <- camera
 * I suppose you could also use a piece of white plastic.  I found that regular paper was
 * too grainy, and affected the quality of the photo.  But, photo paper seems to work well for me.
 *
 * Note: the bulb is very hot!  My piece of paper does not catch on fire, but be careful
 * and do not leave your projector unattended while the bulb is on and the paper is in place!
 * These instructions are for informational purposes only, and I will not be held responsible
 * if you burn your house down or suffer any other negative outcome.
 *
 * When zooming/focusing the camera, recall that some slides are in portrait orientation, and
 * some are in landscape orientation.  The camera can be held in place by putty, a beanbag, a
 * tripod, or whatever.  Set the camera to manual focus mode.  I prefer to use aperture priority
 * mode, but that decision is up to you.  If some of the slides are particularly dark, the shutter
 * speed chosen by the camera could potentially be longer than the delays in the code below will
 * allow for.
 *
 * This project was inspired by Brian A. Bryce's Simple Rapid Slide Digitizer:
 * http://babryce.com/slidedigitizer.html
 * His project is extremely similar, but uses an AVRTiny2313 microcontroller instead of
 * an Arduino.
 */

int ADVANCE_SLIDE_PIN = 46;
int TAKE_PHOTO_PIN = 47;

void setup() {                
  pinMode(ADVANCE_SLIDE_PIN, OUTPUT);     
  pinMode(TAKE_PHOTO_PIN, OUTPUT);     
}

void loop() {
  advanceSlide();
  delay(1000);
  takePhoto();
  delay(1000);
}

void advanceSlide() {
  digitalWrite(ADVANCE_SLIDE_PIN, LOW);
  delay(250);
  digitalWrite(ADVANCE_SLIDE_PIN, HIGH);
}

void takePhoto() {
  digitalWrite(TAKE_PHOTO_PIN, HIGH);
  delay(250);
  digitalWrite(TAKE_PHOTO_PIN, LOW);
}
