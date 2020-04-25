#ifndef RESOURCE_TYPE_H
#define RESOURCE_TYPE_H

#include <string>

// The 5 resource types
enum class resource_type
{
  wood,
  bricks,
  wheat,
  wool,
  ore
};

std::string to_str(const resource_type t) noexcept;

#endif // RESOURCE_TYPE_H
