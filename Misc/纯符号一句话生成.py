chars = "~`!@#$%&*()-=+_[]{};:<>,.?/|"
no = "abcdefghijklmnopqrstuvwkyz"
no = no + no.upper()
for x in "_POST":
    for y in chars:
        test = chr(ord(x) ^ ord(y))
        if test in chars:
            print x + "^" + y + "=" + test
            break
