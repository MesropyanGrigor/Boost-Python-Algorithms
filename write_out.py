import datetime
str_now = str(datetime.datetime.now().date())

with open('out.txt', 'a') as f_d:
    f_d.write("\nDate:    %s\n" % str_now)
    f_d.flush()
    while True:
        data = input()
        if data == 'exit':
            break
        f_d.write(data+'\n')
        f_d.flush()
    
