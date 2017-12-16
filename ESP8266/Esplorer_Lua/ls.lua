#Lista ficheiros
#SPIFFS FS
#Vasco Santos

print ("Current Files:")
for k,v in pairs(file.list()) do print(k.." ("..v.." bytes)") end
print("")
