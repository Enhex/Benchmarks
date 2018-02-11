#include <vector>
#include <stack>
#include <queue>

static void stack_deque(benchmark::State& state) {
	for (auto _ : state)
	{
		std::stack<int> container;

		for (int i = 1000; i-- > 0;)
			container.push(i);

		for (int i = 1000; i-- > 0;) {
			auto& element = container.top();
			benchmark::DoNotOptimize(element);
			container.pop();
		}
	}
}
BENCHMARK(stack_deque);

static void stack_vector(benchmark::State& state) {
	for (auto _ : state)
	{
		std::stack<int, std::vector<int>> container;

		for (int i = 1000; i-- > 0;)
			container.push(i);

		for (int i = 1000; i-- > 0;) {
			auto& element = container.top();
			benchmark::DoNotOptimize(element);
			container.pop();
		}
	}
}
BENCHMARK(stack_vector);

static void queue(benchmark::State& state) {
	for (auto _ : state)
	{
		std::queue<int> container;

		for (int i = 1000; i-- > 0;)
			container.push(i);

		for (int i = 1000; i-- > 0;) {
			auto& element = container.front();
			benchmark::DoNotOptimize(element);
			container.pop();
		}
	}
}
BENCHMARK(queue);
