#ifndef __FIXED__
#define	__FIXED__

class Fixed
{
private:
	int					_val;
	static const int	_fracBits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed&	operator = (const Fixed &fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif

