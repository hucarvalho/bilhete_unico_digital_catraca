import serial
import time
import json
import requests
while True:
    ser = serial.Serial('COM3', 9600)
    # ser.write(b't')
    # #ser.write(b'5') #Prefixo b necessario se estiver utilizando Python 3.X
    # ser.read()
    entrada = ""
    while True:
        entrada = ser.readline()
        time.sleep(1)
        
        if len(entrada) == 7:
            break
        
    
    entrada = str(entrada).split("'")
    print(entrada)
    id =""
    for element in range(0, len(entrada[1])):
        try:
            id = id + str(int(entrada[1][element]))
            print(id)
        except:
            print()
    print(id)
        # Equivalente 116 = t
    res = requests.get("http://localhost:9000/api/consumo/21/"+str(id)) 

    resposta = json.loads(res.content)
    if resposta == 0:
        resposta =2
    # Time entre a conexao serial e o tempo para escrever (enviar algo)
    time.sleep(2) # Entre 1.5s a 2s
    print(resposta)
    
    #comport.write(PARAM_CARACTER)
    ser.write(str(resposta).encode())
    time.sleep(14) 
    retorno=ser.read_all()
    #VALUE_WRITED=ser.readline()
    print(str(retorno) + " é")
    #print (VALUE_SERIAL)
    #print (VALUE_WRITED)
    
    # Fechando conexao serial
    ser.close()