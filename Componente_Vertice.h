#ifndef VERTICES_H
#define VERTICES_H

class Vertices{
	private:
		float anterior;
		float distancia;
		float status;
		
	public:
		float get_anterior();
		void set_anterior(float anterior);
		float get_distancia();
		void set_distancia(float distancia);
		float get_status();
		void set_status(float status);
};

#endif
