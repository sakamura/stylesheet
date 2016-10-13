stylesheet
==========

A clean-room implementation of https://code.google.com/p/stylesheet library meant to be used in non-LGPL project.
The interface is nearly identical to the original.

As added bonus, this tool doesn't require boost, merely the C++11 stdlib.

License: MIT

Current state: Barely tested, compiles on XCode 8.0.

Next steps:
- Testing and fixing bugs.
- Further optimize code and cleanup, I am especially unhappy of a few const removal.
- If needed by someone on another platform, add up makefiles and projects.
- Formal penetration analysis and hack-proofing (this lib could very well be used in a bigger project with public CSS parsing, who knows?)
- Extending the project, new features!
