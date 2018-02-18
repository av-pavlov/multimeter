c = input()[0]
if c>='0' and c<='9':
    print("DIGIT")
elif c>='A' and c<='Z':
    print("CAPITAL")
elif c>='a' and c<='z':
    print("LOWERCASE")
else:
    print("NON-ALPHANUMERIC")
