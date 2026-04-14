void datos_confort_term()
{
h = dht.readHumidity(); //Leemos la Humedad
t = dht.readTemperature(); //Leemos la temperatura en grados Celsius                 
}

void lecturas()
{
//Serial.print("Temperatura= ");
Serial.print(temp);
Serial.print(",");
//Serial.print(" C ");
  
//Serial.print("Humedad ");
Serial.print(h,0);
Serial.print(",");
//Serial.print("%");
//Serial.print("Temperatura: ");
Serial.print(t);
Serial.println("");


}