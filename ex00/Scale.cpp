#include "Scale.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <limits>

/***********            CONSTRUCTOR & DESTRUCTOR            ************/

Scale::Scale( void ): _val("\0"), _cval('\0'), _cerr("Non displayable"), _ival(0), _ierr("\0"), _fval(0.0), _ferr("\0"), _dval(0.0), _derr("\0") {

    std::cout << "Default constructor called -> 0 is set as default" << std::endl;
}

Scale::Scale( std::string const value ) : _val(value), _cval('\0'), _cerr("Non displayable"), _ival(0), _ierr("\0"), _fval(0.0), _ferr("\0"), _dval(0.0), _derr("\0"){

    char    *end;
//reste cas nan, +inf, -inf, +inff, -inff;
//gerer . puis point 
//virer les setter qui servent pas a grand chose ??

    if ((this->getValue()).length() == 1 && !(std::isdigit(this->getValue()[0])))
    {
        this->setCharValue(this->getValue()[0]);
        this->setDoubleValue(this->charToDouble(this->getCharValue()));
        this->doubleToInt(this->getDoubleValue());
        this->doubleToFloat(this->getDoubleValue());
    }
    else 
    {
        long l_num = std::strtol(value.c_str(), &end, 10);
        switch (*end) {
            case '\0' :
                std::cout << "cas ou type est un int" << std::endl;
                if (l_num > std::numeric_limits<int>::max() || l_num < std::numeric_limits<int>::min())
                {

                    this->setIntErr("impossible");
                    this->setFloatErr("impossible");
                    this->setDoubleErr("impossible");
                    this->setCharErr("impossible");
                }
                else
                {
                    this->setIntValue(static_cast<int>(l_num));
                    this->setDoubleValue(this->intToDouble(this->getIntValue()));
                    this->doubleToChar(this->getDoubleValue());
                    this->doubleToFloat(this->getDoubleValue());
                }
                break;
            case '.' :
                {
                    long double ld_num = std::strtold(value.c_str(), &end);
                    if (*end == '\0')
                    {
                        if (ld_num > std::numeric_limits<double>::max() || ld_num < ( (-1) *std::numeric_limits<double>::max()))
                        {
                            this->setIntErr("impossible");
                            this->setFloatErr("impossible");
                            this->setDoubleErr("impossible");
                            this->setCharErr("impossible");
                        }
                        else
                        {
                            this->setDoubleValue(static_cast<double>(ld_num));
                            this->doubleToChar(this->getDoubleValue());
                            this->doubleToFloat(this->getDoubleValue());
                            this->doubleToInt(this->getDoubleValue());
                        }
                    }
                    else if (*end == 'f' && *(end + 1) == '\0')
                    {
                        if (ld_num > std::numeric_limits<float>::max() || ld_num < ( (-1) * std::numeric_limits<float>::max()))
                        {
                            this->setIntErr("impossible");
                            this->setFloatErr("impossible");
                            this->setDoubleErr("impossible");
                            this->setCharErr("impossible");
                        }   
                        else
                            this->setFloatValue(static_cast<float>(ld_num));
                        this->setDoubleValue(this->floatToDouble(this->getFloatValue()));
                        this->doubleToChar(this->getDoubleValue());
                        this->doubleToInt(this->getDoubleValue());
                    }
                    else
                        std::cout << "parametre d'entree : " << value << " non valide"<< std::endl;
                    break;
                }
            default :
                std::cout << "parametre d'entree : " << value << " non valide" << std::endl;
                break;                                                                                                                                                          
        }
    }
}

Scale::Scale( Scale const & ref ): _val(ref.getValue()), _cval(ref.getCharValue()), _cerr(ref.getCharErr()), _ival(ref.getIntValue()), _ierr(ref.getIntErr()), _fval(ref.getFloatValue()), _ferr(ref.getFloatErr()), _dval(ref.getDoubleValue()), _derr(ref.getDoubleErr()) {

    // std::cout << "Copy constructor called" << std::endl;
}

Scale::~Scale( void ) {

    // std::cout << "Destructor called" << std::endl;
}


/***********               GETTER & SETTER             ************/

std::string Scale::getValue( void ) const {
    return (this->_val);
}

char        Scale::getCharValue( void ) const {
    return (this->_cval);
}

int         Scale::getIntValue( void ) const {
    return (this->_ival);
}

float       Scale::getFloatValue( void ) const {
    return (this->_fval);
}

double      Scale::getDoubleValue( void ) const {
    return (this->_dval);
}

std::string Scale::getCharErr( void ) const {
    return (this->_cerr);
}

std::string Scale::getIntErr( void ) const {
    return (this->_ierr);
}

std::string Scale::getFloatErr( void ) const {
    return (this->_ferr);
}

std::string Scale::getDoubleErr( void ) const {
    return (this->_derr);
}

void        Scale::setValue( std::string val ) {
    this->_val = val;
}

void        Scale::setCharValue( char cval ) {
    this->_cval = cval;
}

void        Scale::setIntValue( int ival ) {
    this->_ival = ival;
}

void        Scale::setFloatValue( float fval ) {
    this->_fval = fval;
}

void        Scale::setDoubleValue( double dval ) {
    this->_dval = dval;
}

void        Scale::setCharErr( std::string cerr ) {
    this->_cerr = cerr;
}

void        Scale::setIntErr( std::string ierr ) {
    this->_ierr = ierr;
}

void        Scale::setFloatErr( std::string ferr ) {
    this->_ferr = ferr;
}

void        Scale::setDoubleErr( std::string derr ) {
    this->_derr = derr;
}


/***********                    METHODES                  ************/

// found type to double 
//if double is found these function are not used
double      Scale::charToDouble( char cval ) {
    this->setDoubleValue(static_cast<double>(cval));
    return (this->getDoubleValue());
}

double      Scale::intToDouble( int ival ) {
    this->setDoubleValue(static_cast<double>(ival));
    return (this->getDoubleValue());
}

double      Scale::floatToDouble( float fval ) {
    this->setDoubleValue(static_cast<double>(fval));
    return (this->getDoubleValue());
}

// double to other types
char        Scale::doubleToChar( double dval ) {
    char    c = static_cast<char>(dval);
    if (c >= 32 && c <= 126)
        this->setCharValue(static_cast<char>(dval));
    else if ((this->getValue()).length() > 1)
        this->setCharErr("impossible");
    else
        this->setCharErr("Non displayable");
    this->setCharValue(c);
    return (this->getCharValue());
}

int         Scale::doubleToInt( double dval ) {
    if (dval > std::numeric_limits<int>::max() || dval < std::numeric_limits<int>::min())
        this->setIntErr("impossible");
    //ATTENTION IMPOSSIBLE AUSSI DANS LES CAS INF ET NAN
    int ival = static_cast<int>(dval);

    this->setIntValue(ival);
    return (this->getIntValue());
}

float       Scale::doubleToFloat( double dval ) {
    if (dval > std::numeric_limits<float>::max() || dval < (-1 ) * std::numeric_limits<float>::max() )
        this->setFloatErr("impossible");
    float fval = static_cast<float>(dval);
    this->setFloatValue(fval);
    return (this->getIntValue());
}


/***********                 OPERATOR                 ************/

Scale   & Scale::operator=(Scale const & ref) {
    this->_val = ref.getValue();
    this->_cval = ref.getCharValue();
    this->_ival = ref.getIntValue();
    this->_fval = ref.getFloatValue();
    this->_dval = ref.getDoubleValue();
    this->_cerr = ref.getCharErr();
    this->_ierr = ref.getIntErr();
    this->_ferr = ref.getFloatErr();
    this->_derr = ref.getDoubleErr();
    std::cout << "Copy assignement operator called" << std::endl;
    return (*this);
}

std::ostream   &operator<<(std::ostream & o, Scale const & ref) {
    if ((ref.getCharErr()).empty())
        o << "char: " << ref.getCharValue() << std::endl;
    else
        o << "char: " << ref.getCharErr() << std::endl;
    if ((ref.getIntErr()).empty())
        o << "int: " << ref.getIntValue() << std::endl;
    else
        o << "int: " << ref.getIntErr() << std::endl;
    if ((ref.getFloatErr()).empty())
        o << "float: " << std::setprecision(1) << std::fixed << ref.getFloatValue() << "f" << std::endl;
    else
        o << "float: " << ref.getFloatErr() << std::endl;
    if ((ref.getDoubleErr()).empty())
        o << "double: "  << std::setprecision(1) << std::fixed << ref.getDoubleValue() << std::endl;
    else
        o << "double: " << ref.getDoubleErr() << std::endl;
    return (o);
}
