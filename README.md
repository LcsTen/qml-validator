# QML Validator

QML Validator is a small utility which simply loads the input file and show any
errors that could occur when doing so. It uses QCoreApplication, and as such it
doesn't require a graphical environment to run, as opposed to qmlscene for
example, and as such may be used in situation where a graphical environment
isn't available, such as a continuous integration script.

## Usage

```
qml-validator <input-file>
```
