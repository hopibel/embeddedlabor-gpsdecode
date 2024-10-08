# Fast GPS Decode

Lab exercise:
- decode GPS signal
- implement various optimizations
    - multithreading
    - rearranging logic to avoid conditional branches
    - signal redundancy means we can identify received bit with high confidence without reading the whole sequence
    - use references everywhere to avoid copying overhead
