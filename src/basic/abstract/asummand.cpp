#include "basic/abstract/asummand.h"

ASummand& ASummand::operator+(const ASummand& rightTerm)
{
    m_rightTerm = std::shared_ptr<ASummand>(m_rightTerm);;

    return *this;
}

ASummand& ASummand::operator=(const ASummand& newValue)
{
    m_rightTerm = newValue.m_rightTerm;

    return *this;
}

const std::shared_ptr<ASummand>& ASummand::rightTerm() const
{
    return m_rightTerm;
}

