void data_sd(){ 
  String dataString = "";
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(union_variables_sat);
    dataFile.close();
    // print to the serial port too:
    Serial.print("Envio a SD=");
    Serial.println(union_variables_sat);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void datos_cal_aire()
{
  Serial.println(F("Entrando a leer"));
  union_variables_sat.reserve(200);
  uniendo.reserve(200);

  union_variables_sat.concat(ano); //Fecha

  if (a5==1)
  {
    union_variables_sat.concat(mess); //Fecha
  }
  else
  {
     union_variables_sat.concat(mes); //Fecha
  }

  if (a4==1)
  {
    union_variables_sat.concat(dias); //Fecha
  }
  else
  {
     union_variables_sat.concat(dia); //Fecha
  }

  union_variables_sat.concat(",");
  
  if (a1==1)
  {
    union_variables_sat.concat(horas); //Fecha
  }
  else
  {
     union_variables_sat.concat(hora); //Fecha
  }


    if (a2==1)
  {
    union_variables_sat.concat(minutos); //Fecha
  }
  else
  {
     union_variables_sat.concat(minuto); //Fecha
  }

      if (a3==1)
  {
    union_variables_sat.concat(segundos); //Fecha
  }
  else
  {
     union_variables_sat.concat(segundo); //Fecha
  }
  
  union_variables_sat.concat(",");

  union_variables_sat.concat(h);

  union_variables_sat.concat(",");

  union_variables_sat.concat(t);

  Serial.print("concatenando=");
  Serial.println(union_variables_sat);
  Serial.println(F("Fin de lecturas de sensores"));  
  Serial.println();
}