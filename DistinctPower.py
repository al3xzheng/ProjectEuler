existing = set()
sum = 0;
for i in range(2,101):
    for j in range(2,101):       
        if(i**j not in existing):
            sum = sum + 1;
            existing.add(i**j);
print(sum); 