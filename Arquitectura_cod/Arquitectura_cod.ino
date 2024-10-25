int w=0;
int x=0;
int y=0;
int z=0;
int EstadoA = 0;
int EstadoB = 0;

void setup() {
  // Botones de entrada
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(11, INPUT);// EstadoA
  pinMode(12, INPUT);// EstadoB
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);//led salida
  pinMode(9, OUTPUT);//led salida

  pinMode(6, OUTPUT);//Negativo
  pinMode(13, OUTPUT);//Indefinido
  pinMode(10, OUTPUT);//Infinito
}

void loop() {
  w = digitalRead(2);
  x = digitalRead(3);
  y = digitalRead(4);
  z = digitalRead(5);

  EstadoA = digitalRead(11);
  EstadoB = digitalRead(12);

   digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(6, LOW);
  digitalWrite(13, LOW);
  digitalWrite(10, LOW);
//00 = 0
//10 = 01
//01 = 01
//11 = 10
if(!z && !y && !x && !w){  
  digitalWrite(7, HIGH);
  } else{ 
     digitalWrite(7, LOW);
     }

  //suma 0001
  if(!z && !y && !x && w){

      if(EstadoA ^ EstadoB){
        digitalWrite(8, HIGH);                                           
      }if(EstadoA && EstadoB){
        digitalWrite(9, HIGH);
      }
  }
  //resta 0010
  if(!z && !y && x && !w){

    if(EstadoA ^ EstadoB){
        digitalWrite(8, HIGH);
    }

    if(!EstadoA && EstadoB){
      digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
    }
  }
  //multiplicacion 0011
  if(!z && !y && x && w){
    if(EstadoA && EstadoB){
      digitalWrite(8, HIGH);
    }
  }
  //Division 0100
  if(!z && y && !x && !w){

    if(!EstadoA && !EstadoB){ //0/0
        digitalWrite(13, HIGH);//Indefinido
    }
    if(EstadoA && !EstadoB){// 1/0
        digitalWrite(10, HIGH); //Infinito
    }
    if(EstadoA && EstadoB){
      digitalWrite(8, HIGH);
    }
  }
  //AND 0101
  if(!z && y && !x && w){
    
    if(EstadoA && EstadoB){
      digitalWrite(8, HIGH);
    }
  }
  //OR 0110
  if(!z && y && x && !w){

    if(EstadoA || EstadoB){
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
    } 
  }
  //Not 0111
  if(!z && y && x && w){

      if(!EstadoA){
        digitalWrite(8, HIGH);
      }  if(!EstadoB){
        digitalWrite(9, HIGH);
      }
  }
  //xor 1000
  if(z && !y && !x && !w){

    if(EstadoA ^ EstadoB){
      digitalWrite(8, HIGH);
    }
  }
  //xnor 1001
  if(z && !y && !x && w){
    if(!(EstadoA ^ EstadoB)){
      digitalWrite(8, HIGH);
    }
  }
  //nand 1010
  if(z && !y && x && !w){

    if(!(EstadoA && EstadoB)){
      digitalWrite(8, HIGH);
    }
  }
  //nor 1011
  if(z && !y && x &&w){
    if(!(EstadoA || EstadoB)){
      digitalWrite(8, HIGH);
    }
  }
}