import matplotlib.pyplot as plt

array_sizes = [
    500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400,
    2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300,
    4400, 4500, 4600, 4700, 4800, 4900, 5000, 5100, 5200, 5300, 5400, 5500, 5600, 5700, 5800, 5900, 6000, 6100, 6200,
    6300, 6400, 6500, 6600, 6700, 6800, 6900, 7000, 7100, 7200, 7300, 7400, 7500, 7600, 7700, 7800, 7900, 8000, 8100,
    8200, 8300, 8400, 8500, 8600, 8700, 8800, 8900, 9000, 9100, 9200, 9300, 9400, 9500, 9600, 9700, 9800, 9900, 10000
]

merge_sort_times_arr = [
    1.24813e-308, 2.49625e-309, 4.99251e-310, 9.98502e-311, 1.997e-311, 3.99401e-312, 7.98802e-313, 1.5976e-313,
    3.19521e-314, 0.8, 1.16, 1.232, 1.2464, 1.24928, 1.24986, 1.64997, 1.32999, 1.466, 1.4932, 1.49864, 1.49973,
    1.29995, 1.25999, 1.852, 2.3704, 4.07408, 3.21482, 2.64296, 2.52859, 2.50572, 2.50114, 2.50023, 2.70005, 2.74001,
    2.548, 6.3096, 3.46192, 2.89238, 3.17848, 3.6357, 3.72714, 3.74543, 3.94909, 3.78982, 3.75796, 3.75159, 3.95032,
    3.99006, 4.19801, 4.2396, 4.64792, 4.52958, 5.50592, 5.10118, 5.62024, 5.32405, 5.26481, 6.25296, 7.05059, 5.41012,
    5.28202, 5.2564, 5.85128, 6.17026, 6.23405, 6.24681, 6.84936, 6.56987, 6.31397, 6.46279, 6.49256, 6.49851, 6.6997,
    7.13994, 7.82799, 7.1656, 7.83312, 7.36662, 7.27332, 7.65466, 8.13093, 7.62619, 7.72524, 7.94505, 8.18901, 8.0378,
    7.80756, 7.76151, 8.7523, 9.75046, 8.95009, 9.39002, 8.878, 9.1756, 9.03512, 9.80702
]

merge_sort_times_reverse = [
    8.8934e-308, 1.77868e-308, 3.55736e-309, 7.11472e-310, 1.42294e-310, 2.84589e-311, 0.2, 0.04, 0.008, 0.0016,
    0.60032, 0.120064, 1.02401, 1.2048, 1.24096, 1.44819, 1.48964, 1.29793, 1.25959, 1.25192, 1.25038, 1.45008, 1.29002,
    1.458, 1.8916, 3.97832, 2.39566, 2.07913, 2.41583, 2.48317, 2.69663, 2.53933, 2.70787, 2.74157, 3.14831, 4.62966,
    3.72593, 2.74519, 2.54904, 2.90981, 2.58196, 2.71639, 2.74328, 3.14866, 3.42973, 3.68595, 3.73719, 3.74744, 3.74949,
    3.9499, 4.18998, 3.838, 3.7676, 4.35352, 5.0707, 4.41414, 5.08283, 4.41657, 5.48331, 4.89666, 4.97933, 4.99587,
    5.39917, 5.27983, 5.05597, 5.21119, 5.24224, 5.24845, 5.04969, 5.60994, 5.12199, 5.8244, 5.96488, 6.19298, 6.2386,
    6.24772, 6.04954, 6.60991, 6.72198, 6.3444, 6.66888, 6.53378, 6.50676, 6.70135, 6.94027, 7.38805, 6.47761, 7.09552,
    6.6191, 6.92382, 6.98476, 7.59695, 7.71939, 7.94388, 7.98878, 7.79776
]

merge_sort_times_near = [
    8.89475e-308, 1.77895e-308, 3.5579e-309, 7.1158e-310, 1.42316e-310, 2.84632e-311, 5.69264e-312,
    1.13853e-312, 2.27706e-313, 4.55411e-314, 0.6, 0.32, 1.064, 1.2128, 1.24256, 1.44851, 1.2897,
    1.25794, 1.25159, 1.25032, 1.85006, 1.37001, 1.274, 1.2548, 1.65096, 3.73019, 2.54604, 1.50921,
    1.90184, 2.38037, 2.47607, 2.49521, 2.69904, 2.73981, 3.14796, 5.62959, 3.72592, 2.74518,
    2.54904, 2.50981, 2.50196, 3.10039, 3.42008, 2.88402, 3.1768, 3.63536, 3.72707, 3.94541,
    3.78908, 3.95782, 3.79156, 3.95831, 3.99166, 4.39833, 4.67967, 3.93593, 4.98719, 4.59744,
    5.31949, 4.4639, 4.89278, 5.17856, 5.03571, 5.00714, 5.00143, 5.20029, 5.44006, 5.28801,
    5.0576, 5.41152, 5.0823, 5.41646, 6.08329, 5.81666, 6.56333, 5.91267, 5.78253, 5.95651, 6.5913,
    6.31826, 6.66365, 6.53273, 6.70655, 6.74131, 6.74826, 7.54965, 7.10993, 6.42199, 7.0844,
    6.61688, 7.32338, 7.66468, 7.73294, 7.54659, 7.70932, 8.54186
]

plt.figure(figsize=(14, 10))

plt.plot(array_sizes, merge_sort_times_arr, label='MergeSortArr', color='blue', marker='o')
plt.plot(array_sizes, merge_sort_times_reverse, label='MergeSortReverse', color='orange',
         marker='o')
plt.plot(array_sizes, merge_sort_times_near, label='MergeSortNear', color='green', marker='o')

plt.title(
    'Сравнение MergeSort в зависимости от входных данных')
plt.xlabel('Длина массива')
plt.ylabel('Время выполнения (мс)')
plt.legend()
plt.grid()
plt.xscale('linear')
plt.yscale('linear')
plt.tight_layout()

plt.show()
