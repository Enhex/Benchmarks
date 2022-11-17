import pygal
import os
import csv

# plot
with open('./result.csv') as csvfile:
    line_chart = pygal.Line(logarithmic=True)
    line_chart.title = 'count time / find time'
    line_chart.x_labels = []
    for i in range(1,16):
        line_chart.x_labels += [str(pow(2,i))]

    experiments = {}

    reader = csv.DictReader(csvfile)
    for row in reader:
        experiment_name = row['Group']
        if experiment_name not in experiments:
            experiments[experiment_name] = []
        if row['Experiment'] == 'count':
            experiments[experiment_name].append(float(row['Baseline']))

    for experiment_name in experiments:
        line_chart.add(experiment_name, experiments[experiment_name])

    line_chart.render_to_file('./find_vs_count.svg')