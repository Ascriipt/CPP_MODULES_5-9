#pragma once

# include <string>
# include <stdint.h>
# include <iostream>

struct	Data {
	int			d_int;
	char		d_char;
	void		*d_void;
	size_t		d_size_t;
	std::string	d_string;
};

class Serializer {
	private:
		Serializer();
		Serializer( const Serializer &old );
		~Serializer();

		Serializer &operator=( const Serializer &old );
	public:
		static uintptr_t	serialize( Data *ptr );

		static Data*		deserialize( uintptr_t raw );
};