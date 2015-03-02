import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)

led = 12
GPIO.setup(led, GPIO.OUT)


for x in range(0, 10):
    print "We're on iteration %d" % (x)

    print "  LED going high..."
    GPIO.output(led, 1)

    print "    Sleeping for a few seconds..."
    time.sleep(2)

    print "  LED going low..."
    GPIO.output(led, 0)

    print "    Sleeping for a few seconds..."
    time.sleep(2)

GPIO.cleanup()
