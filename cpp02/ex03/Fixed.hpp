#ifndef __FIXED__
#define	__FIXED__

#include <iostream>

class Fixed
{
private:
	int					_val;
	static const int	_fracBits = 8;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fixed);
	~Fixed();

	static Fixed&	min(Fixed &one, Fixed &other);
	static Fixed&	max(Fixed &one, Fixed &other);
	static const Fixed&	min(const Fixed &one, const Fixed &other);
	static const Fixed&	max(const Fixed &one, const Fixed &other);

	Fixed&					operator = (const Fixed &fixed);
	friend std::ostream&	operator << (std::ostream& out, const Fixed &fixed);

	int						operator > (const Fixed &fixed) const;
	int						operator < (const Fixed &fixed) const;
	int						operator >= (const Fixed &fixed) const;
	int						operator <= (const Fixed &fixed) const;
	int						operator == (const Fixed &fixed) const;
	int						operator != (const Fixed &fixed) const;

	Fixed					operator + (const Fixed &fixed) const;
	Fixed					operator - (const Fixed &fixed) const;
	Fixed					operator * (const Fixed &fixed) const;
	Fixed					operator / (const Fixed &fixed) const;

	Fixed&					operator ++ ();
	Fixed&					operator -- ();
	Fixed					operator ++ (int n);
	Fixed					operator -- (int n);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif
