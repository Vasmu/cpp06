#ifndef _SCALE_HPP_
# define _SCALE_HPP_

// # include <iostream>
# include <string>

class Scale {

    std::string _val;

    char        _cval;
    std::string _cerr;
    int         _ival;
    std::string _ierr;
    float       _fval;
    std::string _ferr;
    double      _dval;
    std::string _derr;

    // bool        _cifd[4];
    

public :
    // ***** Constructor & Destructor *****
	Scale( void );
    Scale( std::string const value);
    Scale( Scale const & ref);
	~Scale( void );

    // ***** Getter *****

    std::string getValue( void ) const;
    char        getCharValue( void ) const;
    int         getIntValue( void ) const;
    float       getFloatValue( void ) const;
    double      getDoubleValue( void ) const;

    std::string getCharErr( void ) const;
    std::string getIntErr( void ) const;
    std::string getFloatErr( void ) const;
    std::string getDoubleErr( void ) const;

    // ***** Setter *****
    void        setValue( std::string val );
    void        setCharValue( char cval );
    void        setIntValue( int ival );
    void        setFloatValue( float fval );
    void        setDoubleValue( double dval );
    void        setCharErr( std::string cerr );
    void        setIntErr( std::string ierr );
    void        setFloatErr( std::string ferr );
    void        setDoubleErr( std::string derr );
 

    // ***** Conversion ***** 

    double      charToDouble( char cval);
    double      intToDouble( int ival );
    double      floatToDouble( float ival );
    char        doubleToChar(double dval );
    int         doubleToInt( double dval );
    float       doubleToFloat( double dval );

    Scale   &operator=(Scale const & ref);
};

std::ostream   &operator<<(std::ostream & o, Scale const & ref);


#endif