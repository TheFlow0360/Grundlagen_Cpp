#ifndef OBJECT_H
#define OBJECT_H

/// This object class serves basically as dummy for an "any object".
/// Later we will learn different possibilities to story "anything" in here.
class Object
{
public:
  Object(char* name);
  ~Object();

  /// Returns ID which was passed in the constructor.
  char* GetName() { return m_name; };

private:

  char* m_name;

  // [This would be a good place for more data...]
};

#endif // OBJECT_H
