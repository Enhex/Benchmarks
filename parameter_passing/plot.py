import pygal
from pygal.style import DarkStyle
import os
import csv

# plot
with open('./result.csv') as csvfile:
    line_chart = pygal.Bar(style=DarkStyle)
    line_chart.title = 'Relative runtime (lower is faster), compiler optimizations off'
    line_chart.x_labels = ['int8', 'int16', 'int32', 'int64', '10 bytes', '100 bytes']

    experiments = {}

    reader = csv.DictReader(csvfile)
    for row in reader:
        experiment_name = row['Experiment']
        if row['Group'] == 'array_1' or row['Group'] == 'array_1000' or row['Group'] == 'array_10000':
            continue
        if experiment_name == 'ref':
            experiment_name = 'reference'
        if experiment_name not in experiments:
            experiments[experiment_name] = []
        experiments[experiment_name].append(float(row['Baseline']))

    for experiment_name in experiments:
        line_chart.add(experiment_name, experiments[experiment_name])

    line_chart.render_to_file('./parameter_passing.svg')