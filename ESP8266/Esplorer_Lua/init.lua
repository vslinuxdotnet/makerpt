#Vasco Santos
#init lua start com protecção loop por serie

print("Init Mem used:",collectgarbage("count")*1024)
print("Init Mem free:", node.heap())
print ("Starting MCU in 5 seconds...")
local aborted = false
led1 = 8
led2 = 0
ledB = 4

function go()
    uart.on('data')
    if aborted == false then
        print('RunScript...') aborted = nil
            --local ok, err = pcall(
           if file.exists('run.lc') then
            dofile('run.lc')
	   else
  	      if file.exists('run.lua') then
                dofile('run.lua')
     end
end

function abort(data)
 print ("**** Boot Aborted! ****") aborted = true uart.on('data') return
end

gpio.mode(led1, gpio.OUTPUT) gpio.mode(led2, gpio.OUTPUT) gpio.mode(ledB, gpio.OUTPUT)
gpio.write(led1, gpio.LOW) gpio.write(led2, gpio.LOW) gpio.write(ledB, gpio.HIGH);
print ("*** Press any key to stop the boot! ***")
tmr.delay(2000000)
uart.on('data', abort, 0)
tmr.alarm(0,3000,0,go)
return
