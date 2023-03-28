

String cnxDATA = "";

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len){
  
  if(type == WS_EVT_CONNECT){

    Serial.println("Websocket client connection received");

  } else if(type == WS_EVT_DISCONNECT){
    
    Serial.println("Client disconnected");
    Serial.println("-----------------------");

  } else if(type == WS_EVT_DATA){

    String ReceivedDataCollector = "" ;

    for(int i=0; i < len; i++) {

          ReceivedDataCollector += (char) data[i];
          
    }

    cnxDATA = ReceivedDataCollector;

  }
  
}

class cnx {

  public:

    void start(){

      while (WiFi.status()!= WL_CONNECTED) {
      
        delay(1000);
        Serial.println("Connecting to WiFi..");
        
      }

      Serial.println(WiFi.localIP());

    }
  
 
};

