#blink sem usar o delay
#Vasco Santos

ledB = 2

tmr.alarm(5,2000,1, function() gpio.write(ledB, gpio.HIGH); end )
tmr.alarm(4,3000,1, function() gpio.write(ledB, gpio.LOW); end )
