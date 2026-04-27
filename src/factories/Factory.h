#ifndef FACTORY_H
#define FACTORY_H

#include <concepts>
#include <functional>

template <
    typename Interface,
    std::derived_from<Interface> Implementation,
    // TODO:  ConstructorArgs instead of empty
    typename CreatorFunction = std::function<std::unique_ptr<Interface>()>>
class Factory
{
    static_assert(
        std::is_invocable_r_v<std::unique_ptr<Interface>, CreatorFunction>,
        "CreatorFunction must return a std::unique_ptr to a type derived from Interface.");

private:
    Factory() {}

    // Delete copy and move constructors/operators
    Factory(const Factory &) = delete;
    Factory(Factory &&) = delete;
    Factory &operator=(const Factory &) = delete;
    Factory &operator=(Factory &&) = delete;

public:
    static Factory &getInstance()
    {
        static Factory instance;
        return instance;
    }

    void setCreator(CreatorFunction func)
    {
        creatorFunction = func;
    }

    std::unique_ptr<Interface> createObject()
    {
        if (!creatorFunction)
        {
            return std::make_unique<Implementation>();
        }
        return creatorFunction();
    }

private:
    CreatorFunction creatorFunction;
};

#endif // FACTORY_H