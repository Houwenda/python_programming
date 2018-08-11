


filedata = open('C:\\Users\\houwd\\Desktop\\task_file_hx9IJZa', 'rb')
i = 0
while i < 5000:
    datastring0 = filedata.read(1)
    if ord(datastring0) >ord('!') and ord(datastring0) <ord('~'):
        datastring1 = filedata.read(1)
        if ord(datastring1) >ord('!') and ord(datastring0) <ord('~'):
            datastring2 = filedata.read(1)
            if ord(datastring2)>ord('!') and ord(datastring0) <ord('~'):
                datastring3 = filedata.read(1)
                if ord(datastring3)>ord('!') and ord(datastring0) <ord('~'):
                    print(datastring0+datastring1+datastring2+datastring3)
    i += 1
