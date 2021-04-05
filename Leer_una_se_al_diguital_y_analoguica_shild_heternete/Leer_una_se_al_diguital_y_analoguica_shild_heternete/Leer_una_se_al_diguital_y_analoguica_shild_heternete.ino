
#include <SPI.h>
#include <Ethernet.h>

byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED};//Declaramos la MAC
IPAddress ip(169,254,250,100);//Declaramos la IP
EthernetServer servidor(80);//Habilitamos el puerto 80

void setup()
{
  Ethernet.begin(mac,ip);//Inicializamos con la IP y la MAC
  servidor.begin();//Se inicia comunicacion a travez del puerto
}

void loop()
{
  EthernetClient cliente = servidor.available();
  if(cliente) 
    {
      boolean lineaenblanco = true;
      while(cliente.connected())//cliente conectado
        {
          if(cliente.available())
           {
             char c=cliente.read();
             
              if (c == '\n' && lineaenblanco)//Si la peticion HTTP ha finalizado
              {
                  //cabesera HTTP estandar
                  cliente.println("HTTP/1.1 200 OK");//Envio de encabezado estandar HTTP
                  cliente.println("Content-Type:text/html");
                  cliente.println("Refresh: 1");
                  cliente.println();
                  
                  //Pagina WEB en HTML
                  cliente.println("Entrada digital:");
                  cliente.print(digitalRead(2));
                  cliente.println("<br/>");
                  cliente.println("<br/>");
                  cliente.println("<br/>");
                  cliente.println("Entrada analogica:");
                  cliente.print(analogRead(0));
                  cliente.println("<br/>");
                  cliente.println("<br/>");
                  cliente.println("<br/>");
                  break;
              }
              
              if(c =='\n')
              {
                lineaenblanco=true;//Comenzar una nueva linea
              }
              else if (c!='\r')
              {
                lineaenblanco=false;//Optenemos un caracter en la linea actual
              }
           }
        }
        delay(1);//damos un tiempo al servidor
        cliente.stop();
    }
}
                
                
                          
          
  

