#include <memory>

class ASummand 
{
private:
    std::shared_ptr<ASummand> m_rightTerm;

public:
    ASummand() = default;
    virtual ~ASummand() = default;

    ASummand& operator+(const ASummand& rightTerm);
    ASummand& operator=(const ASummand& newValue);

    const std::shared_ptr<ASummand>& rightTerm() const;
};
