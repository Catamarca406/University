def count_letters(s):
    lenS=len(s)
    d={'vocali': 0,'consonanti':0}

    for i in range(lenS):
        if (ord(s[i]) >= 65 and ord(s[i])<=90) or (ord(s[i])>= 97 and ord(s[i])<=122):
            if s[i] in "aeiou" or s[i] in "AEIOU":
                d['vocali']+=1
            else :
                d['consonanti']+=1
    return d

s="Hello world"
print(count_letters(s))

#Costo spaziale: O(1)
#Costo temporale: O(n)