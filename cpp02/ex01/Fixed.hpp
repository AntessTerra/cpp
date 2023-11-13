#ifndef __FIXED__
#define	__FIXED__

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
	Fixed&					operator = (const Fixed &fixed);
	friend std::ostream&	operator << (std::ostream& out, const Fixed &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

#endif
