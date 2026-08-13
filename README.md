# AMC APIs

This repository contains the AMC (attocube Motion Controller) API bindings (usable for AMC110 and AMC300), examples and documentation for multiple languages (C, C#, LabVIEW, MATLAB, Python). The APIs expose the AMC device interfaces described in the AMC Interface Manual (see `AMC_Interface_Manual_v1.5.1.pdf`).

## Overview

- Purpose: Control and query AMC positioner hardware (3 axes) over the device Ethernet/RT interfaces.
- Supported languages: C (native DLLs), C#, LabVIEW, MATLAB, Python.

Refer to the full protocol and behavior descriptions in the interface manual: [AMC_Interface_Manual_v1.5.1.pdf](AMC_Interface_Manual_v1.5.1.pdf)

## Python API (quick reference)

The Python package is in `python/amc_api_python`. The primary entrypoint is `amc_api_python.AMC.Device`, which composes subsystems:

- `device.control` — control axes, set amplitudes, enable/disable outputs, closed-loop settings
- `device.move` — move commands and target positions
- `device.status` — status flags, target-range checks, open/closed-loop indicators
- `device.amcids` — IDS-related helpers (soft limits, IDS error states)
- `device.network`, `device.update`, `device.diagnostic`, `device.about`, etc.

Please refer to `python/amc_general_example.py` and `python/amc_ids_closed_loop_example.py` for examples on the usage of the python-api.

## Important API notes (from API and manual)

- Axes indexing: 0..2 (three axes maximum). Many functions accept `axis` parameters limited to these indices.
- Units: positions are typically reported in nm for linear actors and µ° for rotators/goniometers; voltages in mV; frequency values in mHz — check function docstrings for exact units.
- Error handling: most API request wrappers return an `errNo` and values. The Python bindings call `device.handleError(response)` to raise/handle errors automatically.
- Some API-functions require specific sensor types or features to be executed. Please refer to the documentation of the function for detailed information about its intended use.

## Examples and bindings

- C/C++: `c-dll/AMC_API_C` contains platform-specific DLLs and examples.
- C#: `c#/AMC_API_CSharp` includes .NET wrapper and example code.
- LabVIEW: `LabVIEW/` contains VI libraries and example VIs.
- MATLAB: `matlab/` contains `matlabexample.m` and supporting files.
- Python: `python/` contains `amc_general_example.py`, `amc_ids_closed_loop_example.py` and the package `amc_api_python`.

## Documentation

The authoritative protocol description and interface details are in the interface manual included in this repository: [AMC_Interface_Manual_v1.5.1.pdf](AMC_Interface_Manual_v1.5.1.pdf). Use it to check parameter ranges, return semantics, and error codes.

## License

See `LICENSE` at the repository root for licensing terms.
