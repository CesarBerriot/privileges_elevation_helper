```c
#include <privileges_elevation_helper.h>

int main(void)
{   if(!peh_check_privileges())
        peh_elevated_restart();
    // ...
}
```

```cmake
include(FetchContent)

FetchContent_Declare(
    privileges_elevation_helper
    GIT_REPOSITORY https://github.com/CesarBerriot/privileges_elevation_helper.git
    GIT_TAG master
)
FetchContent_MakeAvailable(privileges_elevation_helper)

target_link_libraries(PROJECT_NAME PRIVATE privileges_elevation_helper)
```