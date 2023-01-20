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

Scale::Scale( std::string const value ) : _val(value), _cval('\0'), _cerr("\0"), _ival(0), _ierr("\0"), _fval(0.0), _ferr("\0"), _dval(0.0), _derr("\0"){

    char    *end;
//reste cas nan, +inf, -inf
//gerer le cas ou arguments non valide -> exception ?
//tester des trucs chelou ->overflow d'un int casse tout
//                        ->underflow    casse tout
//                        ->overflow d'un float ca marche 3.40282e+38 si interpreter comme un double
//                        ->undeflow d'un float pas oublier le f
//                        ->overflow d'un double ->ne set pas les autres erreurs a impossible
//                        ->underflow d'un double ->ne set pas les autre a impossible
//DISPLAY DOIT ETRE DIFFERENT ->PLUS PROPRE, utilisation de roundf ? ou ca tronc ?
//virer les setter qui servent pas a grand chose ??

    if ((this->getValue()).length() == 1 && !(std::isdigit(this->getValue()[0])))
    {
        //ici c'est un char.
        // std::cout << "cas ou type est un char" << std::endl;
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
            //ici c'est un int
                std::cout << "cas ou type est un int" << std::endl;
                if (l_num > std::numeric_limits<int>::max() || l_num < std::numeric_limits<int>::min())
                    this->setIntErr("impossible");
                else
                    this->setIntValue(static_cast<int>(l_num));
                this->setDoubleValue(this->intToDouble(this->getIntValue()));
                this->doubleToChar(this->getDoubleValue());
                this->doubleToFloat(this->getDoubleValue());
                break;
            case '.' :
                {
                    long double ld_num = std::strtold(value.c_str(), &end);
                    if (*end == '\0')
                    {
                        //ici c'est un double
                        // std::cout << "cas ou type est un double" << std::endl;
                        if (ld_num > std::numeric_limits<double>::max() || ld_num < ( (-1) *std::numeric_limits<double>::max()))
                            this->_derr = "impossible";
                        else
                            this->setDoubleValue(static_cast<double>(ld_num));
                        this->doubleToChar(this->getDoubleValue());
                        this->doubleToFloat(this->getDoubleValue());
                        this->doubleToInt(this->getDoubleValue());
                    }
                    else if (*end == 'f' && *(end + 1) == '\0')
                    {
                        //ici c'est un float 
                        // std::cout << "cas ou type est un float" << std::endl;
                        if (ld_num > std::numeric_limits<float>::max() || ld_num < ( (-1) * std::numeric_limits<float>::max()))
                            this->_ferr = "impossible";
                        else
                            this->_fval = static_cast<float>(ld_num);
                        this->setDoubleValue(this->floatToDouble(this->getFloatValue()));
                        this->doubleToChar(this->getDoubleValue());
                        this->doubleToInt(this->getDoubleValue());
                    }
                    else
                        std::cout << "parametre d'entree : " << value << " non valide"<< std::endl;
                    //ici c'est une erreur de parametre d'entre type : 123214.toto
                    break;
                }
            default :
                std::cout << "parametre d'entree : " << value << " non valide" << std::endl;
                break;                                                                                                                                                          
        }
    }
    // std::cout << "Value constructor called with value :"<< this->getValue() << std::endl;
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
        o << "float: " << ref.getFloatValue() << "f" << std::endl;
    else
        o << "float: " << ref.getFloatErr() << std::endl;
    if ((ref.getDoubleErr()).empty())
        o << "double: "  << ref.getDoubleValue() << std::endl;
    else
        o << "double: " << ref.getDoubleErr() << std::endl;
    return (o);
}
// << std::setw(4) << std::setfill('0')