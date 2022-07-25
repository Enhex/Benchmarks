import pygal
import os
import csv

# plot
with open('./result.csv') as csvfile:
    line_chart = pygal.Line(logarithmic=True)
    line_chart.title = 'Runtime (us/Iteration)'
    line_chart.x_labels = []
    for i in range(1,21):
        line_chart.x_labels += [str(pow(2,i))]

    experiments = {}

    reader = csv.DictReader(csvfile)
    for row in reader:
        experiment_name = row['Experiment']
        if experiment_name not in experiments:
            experiments[experiment_name] = []
        experiments[experiment_name].append(float(row['us/Iteration']))

    for experiment_name in experiments:
        line_chart.add(experiment_name, experiments[experiment_name])

    line_chart.render_to_file('./search.svg')