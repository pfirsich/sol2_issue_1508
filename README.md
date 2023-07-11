This is a reproduction/experiment repo for issue [#1508](https://github.com/ThePhD/sol2/issues/1508) in [sol2](https://github.com/ThePhD/sol2).

In my initial test I got an error message that does not contain exception information, but after more tests (in this repo), I saw even weirder behaviour.

This is the output for different versions of sol2:

## v3.2.1
```
enter main
MyException
Exception: Foobar
```

This is what it should be!

## v3.3.0
```
enter main
MyException
exit main
```

## eab1430c (`develop` branch at the time of testing this)
```
enter main
MyException
exit main
```
