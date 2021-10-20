#include <celero/Celero.h>

#include <random>
#include <limits>

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <Eigen/Dense>
#include <Eigen/StdVector>

///
/// This is the main(int argc, char** argv) for the entire celero program.
/// You can write your own, or use this macro to insert the standard one into the project.
///
CELERO_MAIN

constexpr int g_samples = 30;
constexpr int g_iterations = 200000;

std::mt19937 rng;

constexpr int number_of_tests = 1;


class GLM_Vec3Fixture : public celero::TestFixture
{
public:
	GLM_Vec3Fixture()
	{
		rng.seed(0);
	}


	std::vector<glm::vec3> vecs;


	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = number_of_tests;

		//for (int i = 0; i < totalNumberOfTests; i++)
		//	problemSpace.emplace_back(int64_t(pow(2, i)));
		problemSpace.emplace_back(10);

		return problemSpace;
	}

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		vecs.reserve(experimentValue.Value);

		auto random = std::bind(std::uniform_real_distribution<float>(std::numeric_limits<float>::min(), std::numeric_limits<float>::max()), rng);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
			vecs.emplace_back(random(), random(), random());
	}
};

class GLM_QuaternionFixture : public celero::TestFixture
{
public:
	GLM_QuaternionFixture()
	{
		rng.seed(0);
	}


	std::vector<glm::quat> quats;


	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = number_of_tests;

		//for (int i = 0; i < totalNumberOfTests; i++)
		//	problemSpace.emplace_back(int64_t(pow(2, i)));
		problemSpace.emplace_back(10);

		return problemSpace;
	}

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		quats.reserve(experimentValue.Value);

		auto random = std::bind(std::uniform_real_distribution<float>(std::numeric_limits<float>::min(), std::numeric_limits<float>::max()), rng);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
			quats.emplace_back(random(), random(), random(), random());
	}
};

class EigenVec3Fixture : public celero::TestFixture
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	EigenVec3Fixture()
	{
		rng.seed(0);
	}


	std::vector<Eigen::Vector3f> vecs;


	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = number_of_tests;

		//for (int i = 0; i < totalNumberOfTests; i++)
		//	problemSpace.emplace_back(int64_t(pow(2, i)));
		problemSpace.emplace_back(10);

		return problemSpace;
	}

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		vecs.reserve(experimentValue.Value);

		auto random = std::bind(std::uniform_real_distribution<float>(std::numeric_limits<float>::min(), std::numeric_limits<float>::max()), rng);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
			vecs.emplace_back(random(), random(), random());
	}
};

class EigenVec4Fixture : public celero::TestFixture
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	EigenVec4Fixture()
	{
		rng.seed(0);
	}

	std::vector<Eigen::Vector4f, Eigen::aligned_allocator<Eigen::Vector4f>> vecs;


	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 4;

		//for (int i = 0; i < totalNumberOfTests; i++)
		//	problemSpace.emplace_back(int64_t(pow(2, i)));
		problemSpace.emplace_back(10);

		return problemSpace;
	}

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		vecs.reserve(experimentValue.Value);

		auto random = std::bind(std::uniform_real_distribution<float>(std::numeric_limits<float>::min(), std::numeric_limits<float>::max()), rng);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
			vecs.emplace_back(random(), random(), random(), random());
	}
};

class EigenQuaternionFixture : public celero::TestFixture
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	EigenQuaternionFixture()
	{
		rng.seed(0);
	}


	std::vector<Eigen::Quaternionf, Eigen::aligned_allocator<Eigen::Quaternionf>> quats;


	std::vector<celero::TestFixture::ExperimentValue> getExperimentValues() const override
	{
		std::vector<celero::TestFixture::ExperimentValue> problemSpace;
		const int totalNumberOfTests = 1;

		//for (int i = 0; i < totalNumberOfTests; i++)
		//	problemSpace.emplace_back(int64_t(pow(2, i)));
		problemSpace.emplace_back(10);

		return problemSpace;
	}

	/// Before each run, build a vector of random integers.
	void setUp(celero::TestFixture::ExperimentValue const& experimentValue) override
	{
		quats.reserve(experimentValue.Value);

		auto random = std::bind(std::uniform_real_distribution<float>(std::numeric_limits<float>::min(), std::numeric_limits<float>::max()), rng);

		for (decltype(experimentValue.Value) i = 0; i < experimentValue.Value; ++i)
			quats.emplace_back(random(), random(), random(), random());
	}
};


BASELINE_F(Vector3_addition, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] + vecs[1]);
}

BENCHMARK_F(Vector3_addition, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] + vecs[1]);
}


BASELINE_F(Vector3_addition_10, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] + vecs[1] + vecs[2] + vecs[3] + vecs[3] + vecs[4] + vecs[5] + vecs[6] + vecs[7] + vecs[8] + vecs[9]);
}

BENCHMARK_F(Vector3_addition_10, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] + vecs[1] + vecs[2] + vecs[3] + vecs[3] + vecs[4] + vecs[5] + vecs[6] + vecs[7] + vecs[8] + vecs[9]);
}


BASELINE_F(Vector3_multiplication, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] * vecs[1]);
}

BENCHMARK_F(Vector3_multiplication, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0].cwiseProduct(vecs[1]));
}


BASELINE_F(Vector3_multiplication_10, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] * vecs[1] * vecs[2] * vecs[3] * vecs[3] * vecs[4] * vecs[5] * vecs[6] * vecs[7] * vecs[8] * vecs[9]);
}

BENCHMARK_F(Vector3_multiplication_10, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		vecs[0].cwiseProduct(
			vecs[1].cwiseProduct(
				vecs[2].cwiseProduct(
					vecs[3].cwiseProduct(
						vecs[3].cwiseProduct(
							vecs[4].cwiseProduct(
								vecs[5].cwiseProduct(
									vecs[6].cwiseProduct(
										vecs[7].cwiseProduct(
											vecs[8].cwiseProduct(vecs[9])
											)
										)
									)
								)
							)
						)
					)
				)
			)
		);
}


BASELINE_F(Vector3_division, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] / vecs[1]);
}

BENCHMARK_F(Vector3_division, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0].cwiseQuotient(vecs[1]));
}


BASELINE_F(Vector3_division_10, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0] / vecs[1] / vecs[2] / vecs[3] / vecs[3] / vecs[4] / vecs[5] / vecs[6] / vecs[7] / vecs[8] / vecs[9]);
}

BENCHMARK_F(Vector3_division_10, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		vecs[0].cwiseQuotient(
			vecs[1].cwiseQuotient(
				vecs[2].cwiseQuotient(
					vecs[3].cwiseQuotient(
						vecs[3].cwiseQuotient(
							vecs[4].cwiseQuotient(
								vecs[5].cwiseQuotient(
									vecs[6].cwiseQuotient(
										vecs[7].cwiseQuotient(
											vecs[8].cwiseQuotient(vecs[9])
											)
										)
									)
								)
							)
						)
					)
				)
			)
		);
}


BASELINE_F(Vector3_dot, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(glm::dot(vecs[0], vecs[1]));
}

BENCHMARK_F(Vector3_dot, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0].dot(vecs[1]));
}


BASELINE_F(Vector3_cross, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(glm::cross(vecs[0], vecs[1]));
}

BENCHMARK_F(Vector3_cross, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0].cross(vecs[1]));
}

BENCHMARK_F(Vector3_cross, Eigen_vec4_cross3, EigenVec4Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(vecs[0].cross3(vecs[1]));
}


BASELINE_F(Vector3_cross_10, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		glm::cross(vecs[0],
			glm::cross(vecs[1],
				glm::cross(vecs[2],
					glm::cross(vecs[3],
						glm::cross(vecs[4],
							glm::cross(vecs[5],
								glm::cross(vecs[16],
									glm::cross(vecs[7],
										glm::cross(vecs[8], vecs[9])
										)
									)
								)
							)
						)
					)
				)
			)
		);
}

BENCHMARK_F(Vector3_cross_10, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		vecs[0].cross(
			vecs[1].cross(
				vecs[2].cross(
					vecs[3].cross(
						vecs[3].cross(
							vecs[4].cross(
								vecs[5].cross(
									vecs[6].cross(
										vecs[7].cross(
											vecs[8].cross(vecs[9])
											)
										)
									)
								)
							)
						)
					)
				)
			)
		);
}

BENCHMARK_F(Vector3_cross_10, Eigen_vec4_cross3, EigenVec4Fixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(
		vecs[0].cross3(
			vecs[1].cross3(
				vecs[2].cross3(
					vecs[3].cross3(
						vecs[3].cross3(
							vecs[4].cross3(
								vecs[5].cross3(
									vecs[6].cross3(
										vecs[7].cross3(
											vecs[8].cross3(vecs[9])
											)
										)
									)
								)
							)
						)
					)
				)
			)
		);
}


BASELINE_F(Quaternion_mul, GLM, GLM_QuaternionFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(quats[0] * quats[1]);
}

BENCHMARK_F(Quaternion_mul, Eigen, EigenQuaternionFixture, g_samples, g_iterations)
{
	celero::DoNotOptimizeAway(quats[0] * quats[1]);
}


BASELINE_F(Quaternion_mul_10, GLM, GLM_QuaternionFixture, g_samples, g_iterations)
{

	celero::DoNotOptimizeAway(quats[0] * quats[1] * quats[2] * quats[3] * quats[3] * quats[4] * quats[5] * quats[6] * quats[7] * quats[8] * quats[9]);
}

BENCHMARK_F(Quaternion_mul_10, Eigen, EigenQuaternionFixture, g_samples, g_iterations)
{

	celero::DoNotOptimizeAway(quats[0] * quats[1] * quats[2] * quats[3] * quats[3] * quats[4] * quats[5] * quats[6] * quats[7] * quats[8] * quats[9]);
}




#ifdef OPTIMIZE_AWAY_BENCHMARKS
BASELINE_F(Vector3_addition_opt, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	auto vec = vec1 + vec2;
}

BENCHMARK_F(Vector3_addition_opt, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	auto vec = vec1 + vec2;
}

BASELINE_F(Vector3_cross_opt, GLM, GLM_Vec3Fixture, g_samples, g_iterations)
{
	auto vec = glm::cross(vec1, vec2);
}

BENCHMARK_F(Vector3_cross_opt, Eigen, EigenVec3Fixture, g_samples, g_iterations)
{
	auto vec = vec1.cross(vec2);
}

BENCHMARK_F(Vector3_cross_opt, Eigen_vec4_cross3, EigenVec4Fixture, g_samples, g_iterations)
{
	auto vec = vec1.cross3(vec2);
}


BASELINE_F(Quaternion_mul_opt, GLM, GLM_QuaternionFixture, g_samples, g_iterations)
{
	auto quat = quat1 * quat2;
}

BENCHMARK_F(Quaternion_mul_opt, Eigen, EigenQuaternionFixture, g_samples, g_iterations)
{
	auto quat = quat1 * quat2;
}
#endif