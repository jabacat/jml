# Guide to Contributions

## Introduction

Hello and welcome to JABACAT! We're happy that you want to contribute to our
projects. However, to maintain order, we ask that you contribute according to
these guidelines to keep with our current practices.

# General Guidelines For All Projects

## GitHub branches and forks

We ask that you not push any code directly to our repositories (the ones on
`https://github.com/jabacat/`), unless it is the very first commit to the
repository. Any commits that are directly pushed will be reverted. As outlined
below, please commit code to `https://github.com/yourusername/` and then make
a PR.

## How should I contribute my changes then?

Please fork the repository and create a pull request. We want to see your code
(and verify that it passes tests!) before we merge it. Please do not merge your
code without asking -- we would like to merge it ourselves once we have approved
it and confirmed that it is good to go.

## Guidelines to opening pull requests

- Please link the relevant issue(s) when you open your pull request.
- If this is not a completed pull request yet and you do *not* want it to be
merged, please mark it as a draft pull request. Many an unfortunate incident has
happened where a pull request was merged in which was not ready to be.
- Tag your pull request with the appropriate tags if need be. This is usually
just a formality as linked issue(s) usually already have flags, but can
sometimes be important, especially if your pull request needs to be tested on
various systems before being merged into the main codebase.

## Code style

Please try to stay consistent with other style within the project. For example,
if `all_names_look_like_this,` please do not add `yourNewMethod` in the middle
unless you have good reason to. While this can and will vary from project to
project, here are some general trends that stay constant across projects that we
ask you to follow for consistency.
- Constants that do not change are in `MACRO_CASE`. This applies especially to
enum values that stand in for some other meaningful data.
- Class names, interface names, etc. begin with capital letters -- function and
variable names do not. Class and interface names with `PascalCase` are preferred
but structs in C could go either `MyStruct` or `my_struct`.
- We prefer opening braces not to go on their own lines.
- Please use blank lines every once in a while. It makes it easy to tell where
one block of code ends and another begins.

## Comments

Comments are very helpful for us to figure out what your code is actually doing,
and to the layers and layers of bug-fixing cycles and refactoring.

Additionally, if you are writing a big new feature or similar and you are
creating a new file, you *must* create a comment at the top containing at the
very least your name, and preferably some description of what the code inside
does.

## What to write
If you'd like to get started contributing but don't know what to do, fear not!
Each project should have an issues tab with things that we want done. If an
issue you'd like to work on has no one assigned to it, feel free to grab it and
start coding away! If it does already have a person assigned to it but you want
to help anyway, reach out to them and see if they'd welcome your help.

Importantly, make sure to pay attention to the issues page as this shows what we
actually want to be worked on. Opening a pull request without a corresponding
issue may or may not be alright. If you're opening a pull request to make a
minor bugfix without opening an issue first, this is good. If you're opening a
2,500-line pull request to refactor half of the codebase and add 5 new features
that we didn't even think about, maybe better to talk to the core developers
about it before sinking all that effort in.

(For what it's worth, the developers of these projects do talk to each other
about them all the time -- feel free to join in these discussions yourself.)

Although we may not want you to open a significant pull request without talking
to anyone about it first, we welcome you to open any and all issues concerning
our projects on the issues page. Chances are you may even find some willing
contributors through there!

# Specific guidelines for JML

The JML core codebase is separated into two main parts -- `core/src/` for the
implementation files, and `core/include/` for the header files. (Why the `jml/`
subdirectory in the `include` folder? So users can `#include <jml/w/ever.hpp>`
when using the code.)

## A warning about headers

Because JML is designed to be a library, please be careful about exactly what
functionality you expose through the headers. If your code modifies the header
files in some non-trivial capacity, please reach out to the devs to be able to
view the API docs for discussion.

## Naming conventions

The entire project's functionality is in the C++ namespace `jml`, and we prefer
`snake_case` over `camelCase.`

## Testing
Though tests are tedious to write, they ensure that our code (somewhat)
functions consistently and as expected. As such, we encourage you to write
tests for any code you add. JML uses the popular
[Catch2](https://github.com/catchorg/Catch2) framework for testing. Their docs,
located under `docs/` in their repository, should be all you need to write
tests (they also have a Discord server for support inquiries). How you write,
express, or format the tests does not matter, as long as they thoroughly test
the code (and bear some semblance of readability). Make sure to also add your
test source to the meson build file.
