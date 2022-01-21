Passthrough
==

This [mc_rtc] controller simply output the joint encoders as joint commands.

This is intended to be used as a simple state monitor for integration work.

Building
--

```shell
cmake -B build -S . -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build . --config RelWithDebInfo
sudo cmake --build . --target install --config RelWithDebi
```

Usage
--

Use the following entry in your mc_rtc configuration file:

```yaml
Enabled: Passthrough
```

[mc_rtc]: https://github.com/jrl-umi3218/mc_rtc
