
#include <SPI.h>
#include <Ethernet.h>

byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED};//Declaramos la MAC
IPAddress ip(169,254,250,100);//Declaramos la IP
EthernetServer servidor(80);//Habilitamos el puerto 80

int PIN_LED=8;//Configuramos el led en el pin 8

String readString = String(30);
String state = String(3);

void setup()
{
  Ethernet.begin(mac,ip);//Inicializamos con la IP y la MAC
  servidor.begin();
  pinMode(PIN_LED,OUTPUT);//definimos "PIN_LED" como salida
  digitalWrite(PIN_LED,HIGH);//definimos al inicio el LED en alto
  state="OFF";
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
             if(readString.length()<30)//Leemos peticion HTTP
              {
                readString.concat(c);//almacena los caracteres en la variable "readString"
              }
              if (c == '\n' && lineaenblanco)//Si la peticion HTTP ha finalizado
              {
                int LED=readString.indexOf("LED=");
                if(readString.substring(LED,LED+5)=="LED=T")
                 {
                   digitalWrite(PIN_LED,LOW);
                   state="ON";
                 }else if(readString.substring(LED,LED+5)=="LED=F")
                  {
                   digitalWrite(PIN_LED,HIGH);
                   state="OFF";
                  }
                  
                  
                  //cabesera HTTP estandar
                  cliente.println("HTTP/1.1 200 OK");
                  cliente.println("Content-Type:text/html");
                  cliente.println();
                  
                  //Pagina WEB en HTML
                  cliente.println("<html>");
                  cliente.println("<head>");
                  cliente.println("<title> LAMPARA ON/OFF </title>");
                  cliente.println("</head>");
                  cliente.println("<body width=100% height=100%>");
                  cliente.println("<center>");
                  cliente.println("<h1> LAMPARA ON/OFF </h1>");
                  cliente.println("<br>");
                  cliente.println("<br>");
                  cliente.println("Estado de la lampara: ");
                  cliente.println(state);
                  cliente.println("<br>");
                  cliente.println("<br>");
                  cliente.println("<br>");
                  cliente.println("<br>");
                  cliente.println("<input type=submit value=ON style=width:200px; height:75px onClick=location.href='./?LED=T\'>");
                  cliente.println("<input type=submit value=OFF style=width:200px; height:75px onClick=location.href='./?LED=F\'>");
                  cliente.println("</center>");
                  cliente.println("</body>");
                  cliente.println("</html>");
                  cliente.stop();//se cierran todas las coneccione con el cliente
                  cliente.println("");
                 readString="";
              }
           }
        }
    }
}
              
          
          
  





