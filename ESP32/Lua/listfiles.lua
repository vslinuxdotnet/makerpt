for k,v in pairs(file.list()) do l = string.format("%-15s",k) print(l.."   "..v.." bytes") end