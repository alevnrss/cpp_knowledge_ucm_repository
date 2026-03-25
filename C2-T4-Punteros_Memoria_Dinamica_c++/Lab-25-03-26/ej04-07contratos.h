#ifndef contratos_h
#define contratos_h

/**
* Tipo enumerado con los valores posibles de contratos
*/
enum tTipoContrato {
	Fijo, Practicas, Eventual, Becario
};

void escribirContrato(tTipoContrato contrato);


#endif