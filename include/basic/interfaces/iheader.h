class IHeader
{

public:
    IHeader() = default;
    virtual ~IHeader() = default;

    /**
    * @brief Set the field corresponding to the specified identifier
    * 
    * @param fieldId - field identifier (int)
    * @param fieldValue - field value (void *)
    * @return Returns the result of the action: 'true' - success, 'false' - failure
    **/
    virtual bool setField(const int fieldId, const void* fieldValue) = 0;

    /**
    * @brief Get the field corresponding to the specified identifier
    *
    * @param fieldId - field identifier (int)
    * @return Returns the result of the action: 'true' - success, 'false' - failure
    **/
    virtual bool field(const int fieldId) const = 0;

private:
    virtual bool headerGenPriv() = 0;
};
