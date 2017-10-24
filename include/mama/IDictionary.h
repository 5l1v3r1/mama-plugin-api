#ifndef MAMA_IDICTIONARY_H
#define MAMA_IDICTIONARY_H

#include <string>

#include <mama/MamaPluginAPI_export.h>

namespace mama {

/**
 * \brief Set of properties.
 */
class MAMAPLUGINAPI_EXPORT IDictionary
{
public:

    virtual ~IDictionary();

    /**
     * \brief Removes all properties.
     */
    virtual void Clear() = 0;

    /**
     * \brief Returns whether this set contains the specified property.
     *
     * \param name Property name.
     * \return \c true if this set contains the specified property; otherwise,
     * \c false.
     */
    virtual bool Contains(const std::string& name) const = 0;

    /**
     * \brief Returns the value of the specified property as a \c bool.
     *
     * \param name Property name.
     * \param ifAbsent Value to return if this set does not contain the
     * specified property or its value is not a \c bool.
     * \return Value of the specified property as a \c bool. If this set does
     * not contain the specified property or its value is not a \c bool, returns
     * \a ifAbsent instead.
     */
    virtual bool GetBool(const std::string& name, bool ifAbsent = false) const = 0;

    /**
     * \brief Returns the value of the specified property as a \c double.
     *
     * \param name Property name.
     * \param ifAbsent Value to return if this set does not contain the
     * specified property or its value is not a \c double.
     * \return Value of the specified property as a \c double. If this set does
     * not contain the specified property or its value is not a \c double,
     * returns \a ifAbsent instead.
     */
    virtual double GetDouble(const std::string& name, double ifAbsent = 0.0) const = 0;

    /**
     * \brief Returns the value of the specified property as an \c int.
     *
     * \param name Property name.
     * \param ifAbsent Value to return if this set does not contain the
     * specified property or its value is not an \c int.
     * \return Value of the specified property as an \c int. If this set does
     * not contain the specified property or its value is not an \c int, returns
     * \a ifAbsent instead.
     */
    virtual int GetInt(const std::string& name, int ifAbsent = 0) const = 0;

    /**
     * \brief Returns the value of the specified property as a \c std::string.
     *
     * \param name Property name.
     * \param ifAbsent Value to return if this set does not contain the
     * specified property or its value is not a \c std::string.
     * \return Value of the specified property as a \c std::string. If this set
     * does not contain the specified property or its value is not a
     * \c std::string, returns \a ifAbsent instead.
     */
    virtual std::string GetString(const std::string& name, const std::string& ifAbsent = std::string()) const = 0;

    /**
     * \brief Sets the value of the specified property as a \c bool.
     *
     * \param name Property name.
     * \param value New value.
     */
    virtual void PutBool(const std::string& name, bool value) = 0;

    /**
     * \brief Sets the value of the specified property as a \c double.
     *
     * \param name Property name.
     * \param value New value.
     */
    virtual void PutDouble(const std::string& name, double value) = 0;

    /**
     * \brief Sets the value of the specified property as an \c int.
     *
     * \param name Property name.
     * \param value New value.
     */
    virtual void PutInt(const std::string& name, int value) = 0;

    /**
     * \brief Sets the value of the specified property as a \c std::string.
     *
     * \param name Property name.
     * \param value New value.
     */
    virtual void PutString(const std::string& name, const std::string& value) = 0;

    /**
     * \brief Removes the specified property.
     *
     * \param name Property name.
     * \return \c true if this set contained the specified property; otherwise,
     * \c false.
     */
    virtual bool Remove(const std::string& name) = 0;
};

} // namespace mama

#endif
