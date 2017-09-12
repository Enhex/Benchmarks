Celero
Celero: CPU processor throttling disabled.
Timer resolution: 0.255488 us
-----------------------------------------------------------------------------------------------------------------------------------------------
     Group      |   Experiment    |   Prob. Space   |     Samples     |   Iterations    |    Baseline     |  us/Iteration   | Iterations/sec  | 
-----------------------------------------------------------------------------------------------------------------------------------------------
equal           | C_string        | Null            |            1000 |            1000 |         1.00000 |         0.03600 |     27777777.78 | 
equal           | string_view     | Null            |            1000 |            1000 |         0.55556 |         0.02000 |     50000000.00 | 
equal           | str_view_c_str  | Null            |            1000 |            1000 |         1.30556 |         0.04700 |     21276595.74 | 
equal           | sv_c_literal    | Null            |            1000 |            1000 |         0.55556 |         0.02000 |     50000000.00 | 
equal           | sv_sv_literal   | Null            |            1000 |            1000 |         0.55556 |         0.02000 |     50000000.00 | 
equal           | string          | Null            |            1000 |            1000 |         0.55556 |         0.02000 |     50000000.00 | 
Complete.
