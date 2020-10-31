#include "Componente_Vertice.h"

float Vertices::get_anterior(){
	return Vertices::anterior;
}

void Vertices::set_anterior(float anterior){
	this->anterior = anterior;
}

float Vertices::get_distancia(){
	return Vertices::distancia;
}

void Vertices::set_distancia(float distancia){
	this->distancia = distancia;
}

void Vertices::set_status(float status){
	this->status = status;
}

float Vertices::get_status(){
	return Vertices::status;
}
